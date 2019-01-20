def Settings(**kwargs):
    return {
        'flags': [
            '-x', 'c++',
            '-Wall', '-Wextra', '-Werror',
            '-I', './src',
            '-std=c++14'
        ],
    }
