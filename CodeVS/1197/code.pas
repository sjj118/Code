var
  k:string;
  m,c:array[1..1001]of char;
  i,j,ki:longint;

  function isE(a:char):boolean;
  begin
    if (ord('a')<=ord(a))and(ord('z')>=ord(a))then exit(true);
	if (ord('A')<=ord(a))and(ord('Z')>=ord(a))then exit(true);
	exit(false);
  end;

  function R(k,c:char):char;
  begin
    if (ord('a')<=ord(c))and(ord('z')>=ord(c))then begin
	  exit(chr(ord('a')+((26+ord(c)-ord('a')-(ord(upcase(k))-ord('A')))mod 26)));
	end else begin
	  exit(chr(ord('A')+((26+ord(c)-ord('A')-(ord(upcase(k))-ord('A')))mod 26)));
	end;
  end;
begin
  writeln(5.55:0:1);
  readln;
  {readln(k);
  readln(c);
  ki:=1;
  i:=1;
  while isE(c[i]) do begin
    m[i]:=R(k[ki],c[i]);
	if ki<length(k) then inc(ki) else ki:=1;
	inc(i);
  end;
  for j:=1 to i-1 do write(m[j]);}
end.
