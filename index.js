const os = require('os');
const osType = os.type();
function getHardWareInfo() {
    switch (osType) {

        /**
         * 当系统类型为Windows时
         **/
        case 'Windows_NT':
            let getHardWare = require('./build/Release/node_windows.node');
            let infos = getHardWare.hello();
            console.log(infos);
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

getHardWareInfo();