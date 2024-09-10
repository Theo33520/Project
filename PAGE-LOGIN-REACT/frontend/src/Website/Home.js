import React, { useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import './style.css';
import backgroundImage from '/home/tfages/Project-Théo/Project/PAGE-LOGIN-REACT/frontend/src/bag.jpg'

const Home = () => {
  const [message, setMessage] = useState('');
  const navigate = useNavigate();

  useEffect(() => {
      document.body.style.backgroundImage = `url(${backgroundImage})`;
      document.body.style.backgroundSize = "cover";
      document.body.style.backgroundPosition = "center";
  }, []);


  const handleFormSubmitted = async (event) => {
    event.preventDefault();
    const username = event.target.username.value;
    const password = event.target.password.value;

    try {
      const response = await fetch('http://localhost:5000/api/users/login', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({ username, password }),
      });

      const result = await response.json();
      if (result.message === 'false') {
        setMessage('Please register you');
      } else {
        navigate(`/userLogged/${username}`);
      }
    } catch (error) {
      console.error('Error:', error);
    }
  };

  return (
    <div className='wrapper'>
      <form onSubmit={handleFormSubmitted}>
        <h1>Sign in</h1>
        <div className="input-box">
          <input type="text" name="username" placeholder="Email" required />
        </div>
        <div className="input-box">
          <input type="password" name="password" placeholder="Password" required />
        </div>
        <button type='submit' className='btn'>Login</button>
        <div className='msg-backAPI'>
          {message}
        </div>
        <div className='register-link'>
          <a href="/register" className='register'>Register</a>
        </div>
      </form>
    </div>
  );
};

export default Home;