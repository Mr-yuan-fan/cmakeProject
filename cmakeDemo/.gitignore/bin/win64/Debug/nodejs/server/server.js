
const http = require('http')

class Server {
    constructor() {};

    init(port) 
    {
        this.port = port;
    }

    startServer() {
        const server = http.createServer()
        server.listen(this.port)
        console.log("server is listening port:",this.port);
    };

   static getInstance() {
        if (!Server.instance) {
            Server.instance = new Server();
        }
        return Server.instance;
    }

}

module.exports = Server.getInstance();