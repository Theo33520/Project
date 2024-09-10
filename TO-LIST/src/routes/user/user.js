const router = require('express').Router();
const  {get_user, create_new_user, login,get_user_to_id_or_mail, updateUser, delete_user} = require('./user.query');
const {get_user_todo, create_new_todo, updateTodo, deleteTodo, get_todo, get_todo_to_id, delete_todo} = require('../todos/todos.query');
const auth = require('../../middleware/auth');
require("dotenv").config();


router.get('/user',auth, (req, res) => {
    if (req.authError) {
        return res.status(401).json(req.authError);
    }
    let id = req.query.id;
    get_user(res,id);
});

router.post('/register', (req, res) => {
    let id = req.query.id;
    create_new_user(req,res,id);
});

router.delete('/users/:id', (req, res) => {
    const UserId = req.params.id;
    delete_user(req,res,UserId);
});

router.delete('/todos/:id', (req, res) => {
    const UserId = req.params.id;
    delete_todo(req,res,UserId);
});

router.post('/login',(req, res) => {
    let id = req.query.id;
    let email = req.body.email;
    let password = req.body.password;
    login(req,res,email,password);
});

router.get('/user/todos',auth,(req, res) => {
    let id = req.query.id;
    get_user_todo(res,1);
});

router.post('/todos',auth,(req, res) => {
    let id = req.query.id;
    create_new_todo(req,res,1);
});


router.put('/todos/:id',auth,(req, res) => {
    const UserId = req.params.id;
    updateTodo(req,res,UserId);
});

router.put('/users/:id',auth,(req, res) => {
    const UserId = req.params.id;
    updateUser(req,res,UserId);
});

router.get('/todos/:id',auth,(req, res) => {
    const UserId = req.params.id;
    get_todo_to_id(res,UserId)
});

router.delete('/todos/:id',auth,(req, res) => {
    const UserId = req.params.id;
    deleteTodo(req,res,UserId);
});

router.get('/users/:idOrEmail', auth, (req, res) => {
    const idOrEmail = req.params.idOrEmail;
    
    let id = null;
    let email = null;
    if (!isNaN(idOrEmail)) {
      id = parseInt(idOrEmail);
    } else {
      email = idOrEmail;
    }
  
    get_user_to_id_or_mail(res, id, email);
});

router.get('/todos',auth,(req, res) => {
    let id = req.query.id;
    get_todo(res,id);
});

module.exports = router;