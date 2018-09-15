const os = require('os');
const osType = os.type();
const crypto = require('crypto');
let getHardWare = require('./build/Release/mechine_code.node');
const secret = "nmc";

function getHardWareInfo() {
    let info;
    switch (osType) {
        /**
         * ��ϵͳ����ΪWindowsʱ
         **/
        case 'Windows_NT':
            infos = getHardWare.exports();
            return infos;
            break;

        /**
         * ��ϵͳ����ΪLinuxʱ
         **/
        case 'Linux':
            infos = getHardWare.exports();
            break;

        /**
         * ��ϵͳ����ΪMac OSʱ
         **/
        case 'Darwin':
            infos = getHardWare.exports();
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