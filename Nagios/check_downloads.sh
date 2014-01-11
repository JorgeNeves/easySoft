#!/bin/bash
#exit 2 - Critical
#exit 1 - Warning
#exit 0 - OK!
#Downloads>5 Warning
#Downloads>100 Critical
#URL do WS
#URL=http://wvm054.dei.isep.ipp.pt/SocialLiteWS/SocialiteWS.svc/status
#RESPONSE=$(curl -i -H "Accept: application/json" -H "Content-Type: application/json" $URL | tail -1)

if [ $RESPONSE > 100 ]; then
        echo "O numero de utilizadores e superior a 100";
		exit 2;
else
        if [ $RESPONSE>5 ] then
			echo "O numero de utilizadores e superior a 5";
			exit 1;
		fi
fi
echo "Numero de Downloads igual ou inferior a 5";
exit 0;


