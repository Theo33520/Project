var db = require('../../config/db');
const jwt = require('jsonwebtoken');
require("dotenv").config();

exports.get_user_todo = function (res, id) {
  let sql = 'SELECT * FROM `todo`';
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

exports.create_new_todo = function (req, res, id) {
  if (!title || !description || !due_time || !status) {
    res.status(400).json({ "msg": "Bad parameters" });
    return;
  }
  const { title, description, due_time, status } = req.body;
  let sql = 'INSERT INTO `todo` (title, description, due_time, status, user_id) VALUES (?, ?, ?, ?, ?)';
  const values = [title, description, due_time, status, id];

  db.query(sql, values, function (err, result, fields) {
    if (err) {
      res.status(500).json({ "msg": "Error wrong user" });
    } else {
      const payload = {
        user_id: id
      };
      const token = jwt.sign(payload, 'moncodesecret');
      res.status(200).json({ "token": token });
    }
  });
}


exports.updateTodo = function (req, res,id) {
    const { title, description, due_time, status } = req.body; 
    if (!title || !description || !due_time || !status) {
      res.status(400).json({ "msg": "Bad parameters" });
      return;
    }
    const sql = `UPDATE todo SET title = ?, description = ?, due_time = ?, status = ? WHERE id = ?`;
    const values = [title, description, due_time, status, id];
    db.query(sql, values, function (err, results, fields) {
      if (err) {
        console.log(err);
        res.status(500).json({ "msg": "Error updating the todo" });
      } else {
        res.status(200).json({ "msg": "Todo updated successfully" });
      }
    });
};

exports.get_todo = function (res, id) {
    let sql = 'SELECT * FROM `todo`';
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

exports.get_todo_to_id = function (res, id) {
    if (id === undefined) {
        res.status(500).json({"msg": "Internal server error"});
            return;
    }
    let sql = 'SELECT * FROM `todo`';
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

exports.delete_todo = function(req, res, id) {
  let sql = `DELETE FROM \`todo\``;
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