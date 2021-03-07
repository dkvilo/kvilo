FROM ubuntu:18.04

RUN useradd -ms /bin/bash david

RUN apt-get update && apt-get install -y build-essential \ 
  locales lib32readline7 lib32readline-dev \
  libreadline-dev libncurses5-dev && rm -rf /var/lib/apt/lists/* \
    && localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8

ENV LANG en_US.utf8

RUN mkdir ~/kvilo

USER david
WORKDIR /home/david

COPY . ~/kvilo
WORKDIR ~/kvilo

USER root
RUN make build

RUN make install_linux

USER david

RUN echo " --- Create Collection myenv ---"
RUN kvilo init

RUN echo " --- Store Key foo with Value of bar in myenv collection ---"
RUN kvilo set myenv foo=bar

RUN echo " --- Get foo value from myenv collection ---"
RUN kvilo get myenv foo

RUN echo " --- Validate foo value in myenv collection ---"
RUN kvilo val myenv foo bar

RUN echo " --- Show Collection ---"
RUN kvilo ls myenv

RUN echo " --- Copy conf.lua ---"
RUN make copy_config

RUN echo " --- Run Macro ---"
RUN kvilo ping
