{
ID: sjj22451
PROG: ride
LANG: PASCAL
}
var
  s1,s2:array[1..7]of char;
  i,k,k2:longint;
begin
  assign(input,'ride.in');reset(input);
  assign(output,'ride.out');rewrite(output);
  readln(s1);
  readln(s2);
  i:=1;
  k:=1;k2:=1;
  while ord(s1[i])>0 do begin k:=k*(ord(s1[i])-ord('A')+1)mod 47; inc(i); end;
  i:=1;
  while ord(s2[i])>0 do begin k2:=k2*(ord(s2[i])-ord('A')+1)mod 47; inc(i); end;
  if k=k2 then writeln('GO') else writeln('STAY');
  close(input);
  close(output);
end.
