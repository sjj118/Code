var
  p,e,i,d,k,j:longint;
begin
  k:=0;
  while true do begin
    readln(p,e,i,d);
	if p=-1 then break;
	inc(k);
	for j:=d+1 to d+21252 do if((j-p)mod 23=0)and((j-e)mod 28=0)and((j-i)mod 33=0)then break;
	writeln('Case ',k,': the next triple peak occurs in ',j-d,' days.');
  end;
end.
