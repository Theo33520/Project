const express = require("express");
const cors = require("cors");

const usersRoutes = require("./routes/Users.js");
const playersRoutes = require("./routes/Players.js");

class HandleRoot {
    constructor() {
        this.routor = express.Router();
        this.FactoryRoot();
    }

    FactoryRoot() {
        this.routor.use('/api/users', usersRoutes);
        this.routor.use('/api/players', playersRoutes);
    }
}

const app = express();
app.use(cors());
app.use(express.json());
const PORT = process.env.PORT || 5000;
const root = new HandleRoot();

app.use('/', root.routor);

app.listen(PORT, (err) => {
    if (err) {
        console.error(`Failed to start server due to error: ${err}`);
    } else {
        console.log(`Server is listening on port ${PORT}`);
    }
});
