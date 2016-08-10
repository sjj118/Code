{
ID: sjj22451
LANG: PASCAL
PROB: friday
}
const
  month:array[1..12]of longint=(31,28,31,30,31,30,31,31,30,31,30,31);
var
  n,i,j,y,x,m:longint;
  c:array[1..7]of longint;

  function rn(n:longint):boolean;
  begin
    rn:=false;
    if (n mod 4=0)and((n mod 100<>0)or(n mod 400=0)) then rn:=true;
  end;

  function day(m:longint):longint;
  begin
    if (m=2)and(rn(y))then day:=29 else day:=month[m];
  end;
begin
  assign(input,'friday.in');reset(input);
  assign(output,'friday.out');rewrite(output);
  readln(n);
  fillchar(c,sizeof(c),0);
  x:=6;
  inc(c[x]);
  for y:=1900 to 1900+n-1 do begin
	for m:=1 to 12 do begin
	  x:=(x+day(m)-1)mod 7+1;
	  inc(c[x]);
	end;
  end;
  dec(c[x]);
  for i:=6 to 7 do write(c[i],' ');
  for i:=1 to 4 do write(c[i],' ');
  writeln(c[5]);
  close(input);
  close(output);
end.
