#!/bin/bash

check_python_installed() {
    if command -v python3 &> /dev/null; then
        echo "Python 3 is installed on this system."
        return 0
    elif command -v python &> /dev/null; then
        echo "Python 2 is installed on this system."
        return 0
    else
        echo "Python is not installed on this system."
        return 1
    fi
}

if check_python_installed; then
    #install conda
    MINICONDA_INSTALLER="https://repo.anaconda.com/miniconda/Miniconda3-latest-Windows-x86_64.exe"
    wget "$MINICONDA_INSTALLER" -O Miniconda3-latest-Windows-x86_64.exe
    ./Miniconda3-latest-Windows-x86_64.exe /InstallationType=JustMe /RegisterPython=0 /S /D=%UserProfile%\Miniconda3
    eval "$HOME/Miniconda3/Scripts/conda init bash"
    sleep 10
    source ~/.bashrc
    conda create -n automata_env python=3.10 -y
    conda activate automata_env
    #install pytorch 
    conda install pytorch torchvision torchaudio cudatoolkit=11.3 -c pytorch -y
    echo "PyTorch installation complete."
    #install other dependencies
    pip install -r requirements.txt

    echo "Installation complete."

else
    exit 1
fi