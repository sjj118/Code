uses math;
const
  maxint64:int64=9223372036854775807;
type
  int128=array[1..2]of int64;
var
  n,m,i,j,k:longint;
  ans:int128;
  a:array[1..80,1..80]of longint;
  f:array[1..80,1..80]of int128;

  procedure print(a:int128);
  begin
    write(a[1]+a[2]*maxint64);
  end;

  procedure println(a:int128);
  begin
    writeln(a[1]+a[2]*maxint64);
  end;

  function plus(a:int128;b:longint):int128;
  begin
    plus[2]:=a[2]+(a[1]+b) div maxint64;
	plus[1]:=(a[1]+b) mod maxint64;
  end;

  function plus(a,b:int128):int128;
  begin
    plus[2]:=a[2]+b[2]+(a[1]+b[1])div maxint64;
	plus[1]:=(a[1]+b[1])mod maxint64;
  end;

  function max(a,b:int128):int128;
  begin
    if a[2]>b[2] then exit(a);
	if a[2]<b[2] then exit(b);
	if a[1]>b[1] then exit(a) else exit(b);
  end;

  function multi(a:int128;b:longint):int128;
  begin
    multi[1]:=a[1]*b div maxint64;
	multi[2]:=a[2]+a[1]*b mod maxint64;
  end;

  function toint128(a:longint):int128;
  begin
    toint128[1]:=a;
	toint128[2]:=0;
  end;

  function max(a,b:longint):longint;
  begin
    if a>b then max:=a else max:=b;
  end;
begin
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do begin
	  read(a[i,j]);
	end;
	readln;
  end;
  for k:=1 to n do begin
    for i:=1 to m do f[i,i]:=toint128(a[k,i]*2);
	for i:=2 to m do begin
      for j:=i-1 downto 1 do begin
	    f[j,i]:=multi(max(plus(f[j+1,i],a[k,j]),plus(f[j,i-1],a[k,i])),2);
	  end;
    end;
	ans:=plus(ans,f[1,m]);
  end;
  println(ans);
end.
