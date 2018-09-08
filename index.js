const os = require('os');
const osType = os.type();
const crypto = require('crypto');

const secret = "nmc";

function getHardWareInfo() {
    switch (osType) {

        /**
         * ��ϵͳ����ΪWindowsʱ
         **/
        case 'Windows_NT':
            let getHardWare = require('./build/Release/node_windows.node');
            let infos = getHardWare.exports();
            return infos;
            break;

        /**
         * ��ϵͳ����ΪLinuxʱ
         **/
        case 'Linux':
            break;

        /**
         * ��ϵͳ����ΪMac OSʱ
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