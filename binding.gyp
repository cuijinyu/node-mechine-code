{
    "targets":[
        {
            "sources":[
                '/src/getMacAddress.cc'
            ],
            'target_name': 'getMacAddress',
            'type':'static_library'
        },
        {
            "sources":[
                '/src/getProcessorId.cc'
            ],
            'target_name': 'getProcessorId',
            'type':'static_library'
        },
        {
            "sources":[
                '/src/getCPUID.cc'
            ],
            'target_name': 'getCPUID',
            'type':'static_library'
        },
        {
            "target_name":"mechine_code",
            "include_dirs":[
                '/src',
                'include'
            ],
            'dependencies':['getMacAddress',
                            'getProcessorId',
                            'getCPUID'],
            "conditions":[
                ["OS=='win'", {
                    "sources":[
                        '/src/node_windows.cc'
                    ],
                }],
                ["OS=='linux'", {
                    "sources":[
                        '/src/node_linux.cc'
                    ],
                }],
                ["OS=='mac'", {
                    
                }]
            ]
        }
    ]
}