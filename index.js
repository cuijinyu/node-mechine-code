const os = require('os');
const osType = os.type();
function getHardWareInfo() {
    switch (osType) {

        /**
         * ��ϵͳ����ΪWindowsʱ
         **/
        case 'Windows_NT':
            let getHardWare = require('./build/Release/node_windows.node');
            let infos = getHardWare.hello();
            console.log(infos);
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

getHardWareInfo();