const express = require("express");
const router = express.Router();

const users = [
  { username: 'user1', password: 'password1' },
  { username: 'user2', password: 'password2' },
];

router.post('/login', (req, res) => {
  const { username, password } = req.body;

  const user = users.find(u => u.username === username);

  if (user) {
    res.json({ message: 'true' });
  } else {
    res.json({ message: 'false' });
  }
});

module.exports = router;