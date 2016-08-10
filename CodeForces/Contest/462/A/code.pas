var
  n,i,j:longint;
  a:array[0..101,0..101]of char;

  function get(x,y:longint):longint;
  var
    i:longint;
  begin
    i:=0;
	if a[x-1,y]='o' then inc(i);
	if a[x+1,y]='o' then inc(i);
	if a[x,y-1]='o' then inc(i);
	if a[x,y+1]='o' then inc(i);
	get:=i;
  end;

  function go():string;
  var
    i,j:longint;
  begin
    for i:=1 to n do for j:=1 to n do if get(i,j) mod 2<>0 then exit('NO');
    exit('YES');
  end;

begin
  readln(n);
  for i:=1 to n do begin
    for j:=1 to n do read(a[i,j]);
	readln;
  end;
  writeln(go);
end.
