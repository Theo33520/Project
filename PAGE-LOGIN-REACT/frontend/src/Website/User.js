import React, { useEffect } from "react";
import { useParams } from "react-router-dom";
import './user.css';
import backgroundImage from '/home/tfages/Project-Théo/Project/PAGE-LOGIN-REACT/frontend/src/bag.jpg'

const User = () => {
  const { username } = useParams();

  useEffect(() => {
    document.body.style.background = "white";
    document.body.style.backgroundSize = "cover";
    document.body.style.backgroundPosition = "center";
  }, []);

  return (
    <div className='user-wrapper'>
      <h1>Welcome, {username}!</h1>
    </div>
  );
};

export default User;
