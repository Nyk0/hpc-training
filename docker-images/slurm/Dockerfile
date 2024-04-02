FROM debian:latest

ARG slurm_version=23.11.5
ARG ompi_version_major=4.1
ARG ompi_version_minor=4.1.6

RUN apt-get update && apt-get install -y vim.tiny gcc g++ wget bzip2 make python3 \
      perl openssh-server netcat-traditional && \
    apt-get clean && \
    wget https://download.schedmd.com/slurm/slurm-$slurm_version.tar.bz2 && \
    tar -xjf slurm-$slurm_version.tar.bz2 && \
    useradd -d /var/slurm -r -u 600 -U slurm && \
    mkdir /var/slurm && chown slurm:slurm /var/slurm && \
    mkdir /etc/slurm && mkdir /run/munge && mkdir /locate && \
    mkdir -p /run/sshd && \
    wget https://download.open-mpi.org/release/open-mpi/v$ompi_version_major/openmpi-$ompi_version_minor.tar.bz2 && \
    tar -xjf openmpi-$ompi_version_minor.tar.bz2 && \
    useradd -s /bin/bash user && mkdir /home/user && chown user:user /home/user && chmod 750 /home/user && \
    echo 'user:azerty' | chpasswd && \
    echo 'root:azerty' | chpasswd

WORKDIR "/slurm-$slurm_version"
RUN ./configure --enable-multiple-slurmd --without-munge && make && make install && make contrib && make install-contrib

WORKDIR "/openmpi-$ompi_version_minor"
RUN ./configure --with-slurm --with-pmi=/usr/local && make && make install
WORKDIR "/"

COPY slurm.conf /etc/slurm/slurm.conf
COPY cgroup.conf /etc/slurm/cgroup.conf

RUN rm -rf slurm-$slurm_version && rm -f slurm-$slurm_version.tar.bz2 && rm -rf openmpi-$ompi_version_minor && \
    rm -f openmpi-$ompi_version_minor.tar.bz2 && ldconfig && \
    echo "export SLURM_CONF=/etc/slurm/slurm.conf" >> /root/.bashrc

CMD exec /bin/bash -c "trap : TERM INT; sleep infinity & wait"
