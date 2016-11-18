#!/bin/bash

# ./tp.sh  -e [path_vers_exemplaire]


while [[ $# -gt 0 ]]
do
key="$1"

case $key in
    -e|--ex_path)
    EX_PATH="$1"
    shift
    ;;
    *)
        echo "Argument inconnu: ${1}"
        echo "Usage du script:"
        echo "./tp.sh -e [path_vers_exemplaire]"
        exit
    ;;
esac
shift
done

./run $EX_PATH
