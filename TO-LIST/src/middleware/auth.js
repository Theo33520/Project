const jwt = require('jsonwebtoken');
const {response} = require("express");
require("dotenv").config();

module.exports = (req, res, next) => {
    let authHeader = req.headers.authorization;
    if (authHeader) {
        const token = authHeader.split(' ')[1];

        jwt.verify(token, process.env.SECRET, (err, decoded) => {
            if (err) {
                console.log(err);
                req.authError = { "msg": "Token is not valid" };
            } else {
                console.log(decoded);
            }
            next();
        });
    } else {
        req.authError = { "msg": "No token, authorization denied" };
        next();
    }
};



