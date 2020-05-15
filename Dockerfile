FROM ubuntu:18.04

MAINTAINER David Kviloria

RUN apt-get update && apt-get install -y build-essential locales && rm -rf /var/lib/apt/lists/* \
    && localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8

ENV LANG en_US.utf8

RUN mkdir ~/kvilo

COPY . ~/kvilo

WORKDIR ~/kvilo

RUN make build

RUN make install_linux

RUN kvilo init

RUN kvilo set foo=bar
RUN kvilo get foo

RUN kvilo val foo bar

RUN kvilo show
RUN kvilo exp env > .env

RUN cat .env

