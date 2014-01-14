#!/bin/bash
#exit 1 - Warning
#exit 0 - OK!
#Sabemos que o WS retorna obrigatoriamente uma string
#Caso retorne uma string vazia ou nula faz exit 1

URL=http://wvm054.dei.isep.ipp.pt/SocialLiteWS/SocialiteWS.svc/status
RESPONSE=$(curl -i -H "Accept: application/json" -H "Content-Type: application/json" $URL | tail -1 |  cut -d ':' -f2 | cut -d ',' -f1 | tr '"' ' ')

if [ ! -z $RESPONSE ]; then

        if [ $RESPONSE == "OK" ]; then
                 echo "O WS retorna um valor valido-Operacional";
                 exit 0;
        else
                echo "O WS retorna um valor invalido-Inoperacional";
                exit 1;
        fi
else
        echo "O WS retorna um valor nulo-Inoperacional";
        exit 1;
fi
