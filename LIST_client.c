link hd;
hd = LISTempty();
hd = LISTcons(10,hd);LISTprint(hd);
hd = LISTcons(20,hd);LISTprint(hd);
printf("%d\n", LISThead(hd));
hd = LISTtail(hd);LISTprint(hd);
printf("length = %d\n", LISTlength(hd));