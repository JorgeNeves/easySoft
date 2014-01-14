#!/bin/bash
#exit 2 - Critical
#exit 1 - Warning
#exit 0 - OK!
#Downloads>5 Warning
#Downloads>100 Critical
#URL do WS
URL=http://wvm054.dei.isep.ipp.pt/SocialLiteWS/SocialiteWS.svc/downloads
RESPONSE=$(curl -i -H "Accept: application/json" -H "Content-Type: text/plain" $URL | tail -1| tr '"' ' ' )

if [ $RESPONSE -gt 100 ]; then
        	echo "O numero de downloads superior a 100- Numero de Downloads esta hora:$RESPONSE";
		exit 2;
else
        if [ $RESPONSE -gt 5 ]; then
		echo "O numero de downloads e superior a 5-Numero de Downloads esta hora:$RESPONSE";
		exit 1;
	fi
fi
echo "Numero de Downloads igual ou inferior a 5-Numero de Downloads esta hora:$RESPONSE";
exit 0;
