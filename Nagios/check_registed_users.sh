#!/bin/bash
#exit 1 - Warning
#exit 0 - OK!

USERSLOG=/tmp/userslog
URL=http://wvm054.dei.isep.ipp.pt/SocialLiteWS/SocialiteWS.svc/status
N_USERS=$(curl -i -H "Accept: application/json" -H "Content-Type: application/json" $URL | tail -1 | cut -d ':' -f3 | cut -d ',' -f1)

if [ -f $USERSLOG ]; then
        N_USERS_OLD=$(head $USERSLOG)
        chmod 766 $USERSLOG
        echo $N_USERS > $USERSLOG
        if [ $N_USERS == $N_USERS_OLD ]; then
                echo "O numero de utilizadores mantem-se:$N_USERS utilizadores";
                exit 0;
        else
                echo "O numero de utilizadores foi alterado:Antes $N_USERS_OLD Agora:$N_USERS";
                exit 1;
        fi
else
        echo $N_USERS > $USERSLOG
        chmod 766 $USERSLOG
        echo "O numero de utilizadores foi alterado:Antes 0 Agora :$N_USERS";
        exit 1;
fi
