var
  t,k:longint;
  a,b:qword;

  function gcd(a,b:qword):qword;
  begin
    if b=0 then exit(a);
	exit(gcd(b,a mod b));
  end;
begin
  readln(t);
  for k:=1 to t do begin
    readln(a,b);
	writeln(a div gcd(a,b)mod 23333*(b mod 23333)mod 23333);
  end;
end.
