# Dev image: ESP-IDF (firmware) + Node (via devcontainer feature) on the Dev Containers
# Debian base. Debian/glibc is required: Espressif's prebuilt Xtensa/RISC-V toolchains do
# not run on musl (Alpine).

FROM mcr.microsoft.com/devcontainers/base:debian-13

ARG IDF_VERSION=v6.0.2
ARG IDF_TARGETS=esp32s3

ENV IDF_PATH=/opt/esp/idf \
    IDF_TOOLS_PATH=/opt/esp \
    IDF_CCACHE_ENABLE=1 \
    DEBIAN_FRONTEND=noninteractive

# build-essential: host toolchain for the posix simulator and host tests.
# bzip2/xz-utils/unzip/zip: extracting idf_tools-downloaded toolchains.
# cmake from Debian (>= IDF's 3.22.1 minimum), used from PATH instead of idf_tools'.
RUN apt-get update && apt-get install -y --no-install-recommends \
      build-essential bison flex gperf ninja-build ccache cmake \
      python3 python3-venv \
      libffi-dev libusb-1.0-0-dev libncurses-dev \
      bzip2 xz-utils unzip zip git-lfs \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

RUN install -d -o vscode -g vscode /opt/esp
USER vscode
RUN git clone --branch "$IDF_VERSION" --depth 1 --recursive --shallow-submodules \
      https://github.com/espressif/esp-idf.git "$IDF_PATH" \
    && "$IDF_PATH/tools/idf_tools.py" --non-interactive install required --targets="$IDF_TARGETS" \
    && "$IDF_PATH/tools/idf_tools.py" --non-interactive install-python-env \
    && echo '. "$IDF_PATH/export.sh" >/dev/null 2>&1 || true' >> /home/vscode/.bashrc
