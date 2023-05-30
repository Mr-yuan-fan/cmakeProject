global.sourceDir = __dirname;

const addon = require("./addon/addon.js")
const server = require("./server/server.js")


async function main() {
    if (!addon.init()) {
        return;
    }

    console.log(addon.getString());
    console.log(addon.setString("single string"));
    console.log(addon.getString());

    console.log(addon.getNumber());
    console.log(addon.setNumber(100));
    console.log(addon.getNumber());

    console.log(addon.setObj({"name":"李四","age":18,"height":180}));
    console.log(addon.getObj());

    console.log(addon.setArray(["张张","李李"]));
    console.log(addon.getArray());
    console.log(addon.generateCustomArrayrray());

    addon.asyncCall();
    console.log("asyncCall func outside after")

    addon.syncCall();
    console.log("syncCall func outside after")

    server.init(8001);
    server.startServer();
}




main();