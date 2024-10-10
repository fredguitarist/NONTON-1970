map $uri $auth {
    ^/bitrix/admin "Restricted Access";
    ^/(horizon|telescope)/ "Restricted Content";
    default "off";
}
