#!/bin/bash

if [[ `uname -s` == 'Linux' ]]; then
    echo "Systype is Linux"
elif [[ `uname -s` == 'Darwin' ]]; then
    echo "Systype is Mac OSX"
fi
