#include<stdio.h>

unsigned char * claseIp(unsigned char byte){
    static unsigned char mascara[4] = {255,0,0,0};
    if (!(byte & 128))
    {
        printf("Es de clase A\n");
    }else if (!(byte &  64))
    {
        printf("Es de clase B\n");
        mascara[1] = 255;
    }else if (!(byte & 32))
    {
        mascara[1] = 255;
        mascara[2] = 255;
        printf("Es de clase C\n");
    }else if (!(byte & 16))
    {
        mascara[1] = 0;
        printf("Es de clase D\n");
    }else{
        mascara[1] = 0;
        printf("Es de clase E\n");
    }
    return mascara;
}

int tipoIp(unsigned char *byte){
    if (byte[0] & 10)
    {
        printf("Es una IP privada\n");
    }else if (byte[0] > 126 && byte[0] > 129)
    {
        printf("Es una IP privada\n");
    }else if (byte[0] & 169  && byte[1] & 254 ){
        printf("Es una IP privada\n");
    }else if (byte[0] & 172  && byte[1] > 15 && byte[1] < 32 )
    {
        printf("Es una IP privada\n");
    }else if (byte[0] & 191 && byte[2] & 2){
        printf("Es una IP privada\n");
    }else if (byte[0] & 192 && (byte[2] & 99 || byte[1] & 168)){
        printf("Es una IP privada\n");
    }else if (byte[0] & 198 && (byte[1] & 18 || byte[1] & 19)){
        printf("Es una IP privada\n");
    }
    
    
}

unsigned char * redIp(unsigned char *Ip, unsigned char *mascara){
    static unsigned char ip_red[4];

    for (char i = 0; i < 4; i++) ip_red[i] = mascara[i] & Ip[i];
    printf("Ip red: %d.%d.%d.%d\n", ip_red[0], ip_red[1], ip_red[2], ip_red[3]);
    return ip_red;
}

unsigned char * broadcastIp(unsigned char *Ip, unsigned char *mascara){
    static unsigned char ip_broadcast[4];
    for (char i = 0; i < 4; i++) {

        ip_broadcast[i] = ~mascara[i] | Ip[i];
    };
    printf("Ip broadcast: %d.%d.%d.%d\n",ip_broadcast[0],ip_broadcast[1],ip_broadcast[2],ip_broadcast[3]);
    return ip_broadcast;
}


void rangoHosts(unsigned char *ipRed, unsigned char *ipBroadcast, unsigned char *mascara){
    unsigned char * inferior = ipRed;
    unsigned char * superior = ipBroadcast;
    
    inferior[3]++;
    superior[3]--;

    printf("Rango de hosts válidos: %d.%d.%d.%d - %d.%d.%d.%d\n",
        inferior[0], inferior[1], inferior[2], inferior[3],
        superior[0], superior[1], superior[2], superior[3]);
}

// 169.253.255.255
int main(){
    unsigned char MR[4] = {192,168,1,3};

    //printf("mascara: %D\n",claseIp(MR[0]));
    unsigned char* mascara = claseIp(MR[0]);
    printf("Mascara: %d.%d.%d.%d\n", mascara[0], mascara[1], mascara[2], mascara[3]);
    tipoIp(MR);
    //redIp();
    rangoHosts(redIp(MR,mascara),broadcastIp(MR,mascara),claseIp(MR[0]));
}