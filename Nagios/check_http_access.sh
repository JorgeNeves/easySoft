#!/bin/bash
#exit 1 - Warning
#exit 0 - OK!
#Sabemos que o WS retorna obrigatoriamente uma string
#Caso retorne uma string vazia ou nula faz exit 1

URL=http://wvm054.dei.isep.ipp.pt/SocialLiteWS/SocialiteWS.svc/Httpaccess
RESPONSE=$(curl -i -H "Accept: application/json" -H "Content-Type: application/json" $URL | tail -1 )

if [ ! -z $RESPONSE ]; then

        if [ $RESPONSE == '"OK"' ]; then
                 echo "A pagina principal retorna um valor valido-Operacional";
                 exit 0;
        else
                echo $RESPONSE;
                exit 2;
        fi
else
        echo $RESPONSE;
        exit 2;
fi
