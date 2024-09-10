const express = require("express")
var bcrypt = require('bcryptjs');
require("dotenv").config();
const db = require('./config/db');
const app = express()

const user = require("./routes/user/user");
const todo = require("./routes/todos/todos");

const {jwt} = require("./middleware/auth");

app.use(express.json());
app.use(express.urlencoded({extended: true}));
app.use('/', user);


app.listen(process.env.PORT,()=>{
  console.log(`Server is running on port ${process.env.PORT}`);
})
