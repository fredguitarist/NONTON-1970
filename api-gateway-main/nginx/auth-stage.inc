map $uri $auth {
    ^/(horizon|telescope)/ "Restricted Content";
    default "Restricted Access";
}
