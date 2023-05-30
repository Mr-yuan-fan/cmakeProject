const fs = require("fs")
const path = require("path")
const addonDebugPath = path.join(global.sourceDir, "../cplusExtension.node")


class Addon {
    constructor() {
        this.addon;
    };

    init() {
        if (!fs.existsSync(addonDebugPath)) {
            console.log("invalid addon path")
            return false;
        }
        const { MyAddon } = require(addonDebugPath);
        this.addon = new MyAddon;
        return true;
    }

    setNumber(val) {
        return this.addon.setNumber(val);
    };

    getNumber() {
        return this.addon.getNumber();
    }

    setString(val) {
        return this.addon.setString(val);
    };

    getString() {
        return this.addon.getString();
    }

    setObj(val) {
        return this.addon.setObj(val);
    };

    getObj() {
        return this.addon.getObj();
    }

    setArray(val) {
        return this.addon.setArray(val);
    };

    getArray() {
        return this.addon.getArray();
    }

    generateCustomArrayrray() {
        return this.addon.generateCustomArray() 
    }
    

    async asyncCall() {
        return new Promise((resolve, reject) => {
            this.addon.asyncCall(3, (err, res) => {
                if (err) {
                    console.log("asyncCall err  = ", err);
                    reject(err);
                } else {
                    console.log("asyncCall res = ", res);
                    resolve(res);
                }

            });
            console.log("asyncCall func inner after")
        }).catch((err) => {
            console.log("catch err :", err);
        })
    }

    syncCall() {
        this.addon.syncCall(1, (res) => {
            console.log("syncCall res = ", res);
        });
    }
    static getInstance() {
        if (!Addon.instance) {
            Addon.instance = new Addon();
        }
        return Addon.instance;
    }

}

module.exports = Addon.getInstance();