FROM ubuntu:18.04

RUN apt-get update && apt-get install -y build-essential locales && rm -rf /var/lib/apt/lists/* \
    && localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8

ENV LANG en_US.utf8

RUN mkdir ~/kvilo

COPY . ~/kvilo
WORKDIR ~/kvilo

RUN make build

RUN make install_linux
RUN MAKE copy_config

RUN echo " --- Create Collection myenv ---"
RUN kvilo init myenv

RUN echo " --- Store Key foo with Value of bar in myenv collection ---"
RUN kvilo set myenv foo=bar

RUN echo " --- Get foo value from myenv collection ---"
RUN kvilo get myenv foo

RUN echo " --- Validate foo value in myenv collection ---"
RUN kvilo val myenv foo bar

RUN echo " --- Show Collection ---"
RUN kvilo ls myenv

RUN echo " --- Run Macro ---"
RUN kvilo ping
