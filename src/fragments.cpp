#include "fragments.h"

String Fragments::connect(String bridgeAddr)
{
    time_t now = time(NULL);
    String connectString = "{\
    \"type\" : \"BridgeEvent\",\
    \"json_payload\" : {\
        \"ncp_version\" : \"0x46C5\",\
        \"uptime\" : \"45.71 23.94\",\
        \"firmware_version\" : \"v2.3.1-f3c7946\",\
        \"network_info\" : {\
            \"extended_pan_id\" : \"0x42455247fbbbbd7f\",\
            \"node_type\" : \"EMBER_COORDINATOR\",\
            \"radio_power_mode\" : \"EMBER_TX_POWER_MODE_BOOST\",\
            \"security_level\" : 5,\
            \"network_status\" : \"EMBER_JOINED_NETWORK\",\
            \"channel\" : 11,\
            \"security_profile\" : \"Custom\",\
            \"power\" : 8,\
            \"node_eui64\" : \"0x000d6f0001b3719d\",\
            \"pan_id\" : \"0xDF3A\",\
            \"node_id\" : \"0x0000\"\
        },\
        \"name\" : \"power_on\",\
        \"local_ip_address\" : \"192.168.1.98\",\
        \"uboot_environment\" : \"YXBwZW5kX3J1bl9tb2RlPXNldGVudiBib290YXJncyAke2Jvb"
                           "3RhcmdzfSBydW5tb2RlPSR7cnVubW9kZX07CmF1dG9sb2Fk"
                           "W5vCmJhdWRyYXRlPTExNTIwMApib2FyZF9tYW51ZmFjdHVy"
                           "ZV9pbmZvPUJSSURHRUFBMTI0MzA0MzYKYm9vdGFyZ3M9Y29"
                           "uc29sZT10dHlTMCwxMTUyMDAgcm9vdD0vZGV2L210ZGJsb2"
                           "NrNSBtdGRwYXJ0cz1hdG1lbF9uYW5kOjEyOGsoYm9vdHN0c"
                           "mFwKXJvLDI1NmsodWJvb3Qpcm8sMTI4ayhlbnYxKXJvLDEy"
                           "OGsoZW52MilybywyTShsaW51eCksLShyb290KSBydyByb29"
                           "0ZnN0eXBlPWpmZnMyCmJvb3RjbWQ9cnVuIGNhdGNoX2J0bj"
                           "sgcnVuIGluc3RfaWZfcmVxdWlyZWQ7IHJ1biBhcHBlbmRfc"
                           "nVuX21vZGU7IHJ1biByZXNldF9sZWRzOyBuYW5kIHJlYWQg"
                           "JHtrZXJuZWxfbG9hZF9hZGRyZXNzfSAke2tlcm5lbF9mbGF"
                           "zaF9hZGRyZXNzfSAke2tlcm5lbF9zaXplfTsgYm9vdG0gJH"
                           "trZXJuZWxfbG9hZF9hZGRyZXNzfQpib290ZGVsYXk9MQpjY"
                           "XRjaF9idG49c2V0ZW52IHJ1bm1vZGUgc3RhbmRhcmQ7IHNl"
                           "dGVudiBsb29wIDE7IHdoaWxlIHRlc3QgJHtsb29wfSAtZXE"
                           "gIjEiIDsgZG8gcnVuIGZsYXNoX3doZW5faGVsZDsgZG9uZT"
                           "sgc2V0X2Nsb3VkX2xlZCAwOyBzZXRfZXRoX2xlZCAwOyBzZ"
                           "XRfemlnYmVlX2xlZCAwCmV0aGFjdD1tYWNiMApldGhhZGRy"
                           "PTQwOkQ4OjU1OjAxOkMxOkIzCmZhY3RvcnlfZmV0Y2hfaW1"
                           "hZ2U9ZGhjcDsgdGZ0cCAweDIwODAwMDAwIGZhY3RvcnlfZm"
                           "xhc2guaW1nCmZhY3RvcnlfcnVuX2ltYWdlPXNvdXJjZSAwe"
                           "DIwODAwMDAwCmZhY3Rvcnlfc2V0dXA9cnVuIGZhY3Rvcnlf"
                           "ZmV0Y2hfaW1hZ2UgZmFjdG9yeV9ydW5faW1hZ2UKZmFpbF9"
                           "sb29wPXNldGVudiBsb29wIDE7IHdoaWxlIHRlc3QgJHtsb2"
                           "9wfSAtZXEgIjEiIDsgZG8gbGVkX3NlcSAwOyBkb25lCmZpb"
                           "GVhZGRyPTIwMDAwMDAwCmZpbGVzaXplPTEwRTUwM0MKZmxh"
                           "c2hfd2hlbl9oZWxkPWdldF9lbmdfYnRuOyBpZiB0ZXN0ICQ"
                           "/IC1lcSAwOyB0aGVuIHNldGVudiBydW5tb2RlIGVuZ3Rlc3"
                           "Q7IGxlZF9zZXEgMTsgZWxzZSBzZXRlbnYgbG9vcCAwOyBma"
                           "TsKZ2F0ZXdheWlwPTEwLjEwLjAuMQppbnN0X2ZldGNoX2lt"
                           "YWdlPWRoY3A7IHRmdHAgJHtrZXJuZWxMb2FkQWRkcn0gJHt"
                           "mYWN0b3J5U2NyaXB0RmlsZW5hbWV9Cmluc3RfaWZfcmVxdW"
                           "lyZWQ9aWYgdGVzdCAiJHtydW5tb2RlfSIgPSAiZW5ndGVzd"
                           "CI7IHRoZW4gcnVuIGluc3Rfc2V0dXA7IGZpOwppbnN0X3J1"
                           "bl9pbWFnZT1zb3VyY2UgJHtrZXJuZWxMb2FkQWRkcn0KaW5"
                           "zdF9zZXR1cD1ydW4gZmFjdG9yeV9mZXRjaF9pbWFnZSBmYW"
                           "N0b3J5X3J1bl9pbWFnZQppcGFkZHI9MTAuMTAuMC4yNwprZ"
                           "XJuZWxfZmlsZW5hbWU9dUltYWdlCmtlcm5lbF9mbGFzaF9h"
                           "ZGRyZXNzPTB4YTAwMDAKa2VybmVsX2xvYWRfYWRkcmVzcz0"
                           "weDIwODAwMDAwCmtlcm5lbF9zaXplPTB4MjAwMDAwCm1lbV"
                           "9sb2FkX2FkZHJlc3M9MHgyMDAwMDAwMApuZXRtYXNrPTI1N"
                           "S4yNTUuMjQ4LjAKcmVzZXRfbGVkcz1zZXRfZXRoX2xlZCAw"
                           "OyBzZXRfemlnYmVlX2xlZCAwOyBzZXRfY2xvdWRfbGVkIDA"
                           "7CnJvb3Rmc19lcmFzZV9zaXplPTB4ZmQ2MDAwMApyb290Zn"
                           "NfZmlsZW5hbWU9cm9vdGZzLmpmZnMyCnJvb3Rmc19mbGFza"
                           "F9hZGRyZXNzPTB4MmEwMDAwCnJvb3Rmc193cml0ZV9zaXpl"
                           "PTB4MTUwMDAwMApzZXJ2ZXJpcD0xMC4xMC4wLjEKc3RkZXJ"
                           "yPXNlcmlhbApzdGRpbj1zZXJpYWwKc3Rkb3V0PXNlcmlhbA"
                           "p3cml0ZV9rZXJuZWw9ZWNobyAiRmV0Y2ggKyBXcml0ZSBrZ"
                           "XJuZWwiOyBtdy5iICR7bWVtX2xvYWRfYWRkcmVzc30gMHhm"
                           "ZiAke2tlcm5lbF9zaXplfTsgdGZ0cCAke21lbV9sb2FkX2F"
                           "kZHJlc3N9ICR7a2VybmVsX2ZpbGVuYW1lfTsgbmFuZCBlcm"
                           "FzZSAke2tlcm5lbF9mbGFzaF9hZGRyZXNzfSAke2tlcm5lb"
                           "F9zaXplfTsgbmFuZCB3cml0ZSAke21lbV9sb2FkX2FkZHJl"
                           "c3N9ICR7a2VybmVsX2ZsYXNoX2FkZHJlc3N9ICR7a2VybmV"
                           "sX3NpemV9Owp3cml0ZV9yb290ZnM9ZWNobyAiRmV0Y2ggKy"
                           "BXcml0ZSByb290ZnMiOyBtdy5iICR7bWVtX2xvYWRfYWRkc"
                           "mVzc30gMHhmZiAke3Jvb3Rmc193cml0ZV9zaXplfTsgdGZ0"
                           "cCAke21lbV9sb2FkX2FkZHJlc3N9ICR7cm9vdGZzX2ZpbGV"
                           "uYW1lfTsgc2V0X2Nsb3VkX2xlZCAxOyBuYW5kIGVyYXNlIC"
                           "R7cm9vdGZzX2ZsYXNoX2FkZHJlc3N9ICR7cm9vdGZzX2VyY"
                           "XNlX3NpemV9OyBuYW5kIHdyaXRlICR7bWVtX2xvYWRfYWRk"
                           "cmVzc30gJHtyb290ZnNfZmxhc2hfYWRkcmVzc30gJHtyb29"
                           "0ZnNfd3JpdGVfc2l6ZX07Cg==\",\
        \"mac_address\" : \"40:d8:55:01:c1:b3\",\
        \"model\" : \"A\"\
        },\
    \"bridge_address\" : \"" +
                           bridgeAddr + "\",\
    \"timestamp\" : " + now +
                           "\
}";
    return connectString;
}