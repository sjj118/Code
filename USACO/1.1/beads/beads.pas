{
ID: sjj22451
LANG: PASCAL
PROB: beads
}
var
  n,i,j,t,k,max:longint;
  z:array[1..350]of char;
  d:char;

  function c(a:longint):longint;
  begin
    c:=((a-1+n) mod n)+1;
  end;

  function c2(a:longint):longint;
  begin
    c2:=(a+n) mod n;
  end;
begin
  assign(input,'beads.in');reset(input);
  assign(output,'beads.out');rewrite(output);
  readln(n);
  readln(z);
  for i:=1 to n do begin
    j:=i;
	d:=z[i];
	while ((z[c(j+1)]=d) or (z[c(j+1)]='w') or (d='w'))and(c(j+1)<>i) do begin
          j:=c(j+1);
          if d='w' then d:=z[j];
        end;
	t:=j;
	k:=c2(j-i)+1;
	j:=c(i-1);
        if j<>t then begin
	d:=z[j];
	while ((z[c(j-1)]=d) or (z[c(j-1)]='w') or (d='w'))and(c(j-1)<>t)and(c(j-1)<>i) do begin
          j:=c(j-1);
          if d='w' then d:=z[j];
        end;
	k:=k+c2(i-j);
        end;
	if k>max then max:=k;
  end;
  writeln(max);
  close(input);
  close(output);
end.
