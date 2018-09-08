const os = require('os');
const osType = os.type();
const crypto = require('crypto');

const secret = "nmc";

function getHardWareInfo() {
    switch (osType) {

        /**
         * 当系统类型为Windows时
         **/
        case 'Windows_NT':
            let getHardWare = require('./build/Release/node_windows.node');
            let infos = getHardWare.exports();
            return infos;
            break;

        /**
         * 当系统类型为Linux时
         **/
        case 'Linux':
            break;

        /**
         * 当系统类型为Mac OS时
         **/
        case 'Darwin':
            break;
    }
}

function hash(text) {
    let hashResult = crypto.createHmac('sha256', secret).update(text).digest('hex');
    return hashResult;
}

module.exports = () => {
    let info = getHardWareInfo();
    let str = `${info.baseBoardSerialNumber}${info.processorId}${info.macAddress}`;
    console.log(str);
    let res = hash(str);
    console.log(res);
    return res;
}