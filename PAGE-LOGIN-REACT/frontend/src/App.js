import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Home from './Website/Home';
import User from './Website/User';
import Register from './Website/Register';

const App = () => {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/userLogged/:username" element={<User />} />
        <Route path="/register" element={<Register />} />
      </Routes>
    </Router>
  );
};

export default App;
