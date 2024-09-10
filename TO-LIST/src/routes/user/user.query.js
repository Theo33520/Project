var db = require('../../config/db');
const jwt = require('jsonwebtoken');
require("dotenv").config();

/*register*/
exports.create_new_user = function (req,res, id) {
    const {email,password,name,firstname} = req.body;
    let sql = `INSERT INTO \`user\` (email, password, name, firstname) VALUES (?, ?,?, ?)`;
    const values = [email, password, name, firstname];
    if (id)
    sql += ` WHERE id = ${db.escape(id)}`;
    values.push(db.escape(id));
    if (!email || !password || !name || !firstname) {
      res.status(400).json({ "msg": "Bad parameters" });
      return;
    }
    db.query(sql, values,function (err, result, fields) {
        if (err) {
            res.status(500).json({ "msg": "Account already exists" });
        }
        else {
            res.status(200).json({"token" : "Token of the newly registered user"});
        }
    });
}

/* login */
exports.login = function (req, res,email,password) {
    let sql = "SELECT * FROM `user`";

    if (email === undefined || password === undefined) {
        res.status(500).json({"msg": "Internal server error"});
        return;
    }

    if (email && password) {
        sql += ` WHERE email = ${db.escape(email)} AND password = ${db.escape(password)}`;
    } else {
        res.status(401).json({"msg": "Invalid Credentials"});
        return;
    }
    db.query(sql, function (err, result, fields) {
        if (err) {
            res.status(500).json({"msg": "Internal server error"});
            return;
        }
        if (result.length > 0) {
            const token = jwt.sign({email: email, id: result[0].id}, 'moncodesecret');
            res.status(200).json({"token": "Token of the newly logged in user"});
        } else {
            res.status(401).json({"msg": "Invalid Credentials"});
        }
    });
};


/*user*/
exports.get_user = function (res, id) {
    let sql = 'SELECT * FROM `user`';
    if (id) {
        sql += ' WHERE id = ' + db.escape(id);
    }
    db.query(sql, function(err, results, fields) {
        if (err) {
            res.status(500).json({"msg" : "Token is  not valid"});
        } else {
            const token = jwt.sign({ id: id }, 'moncodesecret');
            res.status(200).json({ results: results, token: token });
        }
    });
}

exports.updateUser = function (req, res, id) {
    const { email, password, name, firstname } = req.body;
    const sql = `UPDATE user SET email = ?, password = ?, name = ?, firstname = ? WHERE id = ?`;
    const values = [email, password, name, firstname, id];
    if (!email || !password || !name || !firstname) {
      res.status(400).json({ "msg": "Bad parameters" });
      return;
    }
    db.query(sql, values, function (err, results, fields) {
      if (err) {
        console.log(err);
        res.status(500).json({ "msg": "Error updating the user" });
      } else {
        res.status(200).json({ "msg": "User updated successfully" });
      }
    });
};

  exports.get_user_to_id_or_mail = function(res,id,email) {
    let sql = 'SELECT * FROM `user`';
    let whereClause = '';
  
    if (id) {
      whereClause = ' WHERE id = ' + db.escape(id);
    } else if (email) {
      whereClause = ' WHERE email = ' + db.escape(email);
    }
  
    sql += whereClause;
  
    db.query(sql, function (err, results, fields) {
      if (err) {
        res.status(500).json({ error: 'Internal Server Error' });
      } else {
        if (results.length > 0) {
          const token = jwt.sign({ id: results[0].id }, 'moncodesecret');
          res.status(200).json({ user: results[0], token: token });
        } else {
          res.status(404).json({ error: 'User not found' });
        }
      }
    });
}

exports.delete_user = function(req, res, id) {
  let sql = `DELETE FROM \`user\``;
  if (id)
    sql += ` WHERE id = ${db.escape(id)}`;
  db.query(sql, function(err, result) {
    if (err) {
      res.status(500).json({ "msg": `Failed to delete user with id: ${db.escape(id)}` });
    } else {
      res.status(200).json({ "msg": `Successfully deleted user with id: ${db.escape(id)}` });
    }
  });
}
