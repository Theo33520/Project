const express = require("express");
const mysql = require('mysql2');
const util = require('util');

require('dotenv').config();
const app = express();
const port = 3000;


const connexion = mysql.createConnection({
  host: process.env.MYSQL_HOST,
  password: process.env.MYSQL_ROOT_PASSWORD,
  user: process.env.MYSQL_USER,
  database: process.env.MYSQL_DATABASE
});

connexion.query = util.promisify(connexion.query).bind(connexion);

connexion.connect(function(err) {
  if (err) {
    console.log('conexion is not possible')
    return;
  }
  console.log('MYSQL Connected...' + connexion.threadId)
});

module.exports = connexion;
