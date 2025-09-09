FROM ubuntu:22.04

# add software repositories for retrieving latest clang-format
# refresh the package index for latest software packages
# install wget and gnupg packages
# retrieve the archive signature for clang-format
# refresh the package index for latest software packages
# install necessary packages
# remove unnecessary packages
RUN DEBIAN_FRONTEND=noninteractive \
    echo "\ndeb http://apt.llvm.org/jammy/ llvm-toolchain-jammy main\
    \ndeb-src http://apt.llvm.org/jammy/ llvm-toolchain-jammy main\
    \n# 19\
    \ndeb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-19 main\
    \ndeb-src http://apt.llvm.org/jammy/ llvm-toolchain-jammy-19 main\
    \n# 20\
    \ndeb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-20 main\
    \ndeb-src http://apt.llvm.org/jammy/ llvm-toolchain-jammy-20 main" >> /etc/apt/sources.list &&\
    apt-get update &&\
    apt-get install -y wget gnupg &&\
    wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - &&\
    apt-get update &&\
    apt-get install -y clang clang-format cppcheck git make unzip &&\
    apt-get remove -y gnupg wget

# set the working directory
WORKDIR /home
