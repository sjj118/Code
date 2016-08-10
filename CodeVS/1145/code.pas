type
  big=record
    data:array[1..100]of byte;
	len:longint;
  end;
var
  i,n:longint;

  function jia1(a:big):big;
  var
    i:longint;
  begin
    with a do begin
	  data[1]:=data[1]+1;
	  i:=1;
	  while data[i]div 10 >0 do begin
	    data[i+1]:=data[i+1]+data[i]div 10;
		data[i]:=data[i]mod 10;
		inc(i);
	  end;
	  if data[len+1]<>0 then inc(len);
	end;
	exit(a);
  end;

  function cheng2(a:big):big;
  var
    i:longint;
  begin
    fillchar(cheng2.data,sizeof(cheng2.data),0);
    cheng2.len:=a.len;
	for i:=1 to cheng2.len do begin
	  cheng2.data[i]:=a.data[i]*2;
	end;
	for i:=1 to cheng2.len do begin
	  cheng2.data[i+1]:=cheng2.data[i+1]+cheng2.data[i]div 10;
	  cheng2.data[i]:=cheng2.data[i]mod 10;
	end;
	if cheng2.data[cheng2.len+1]<>0 then inc(cheng2.len);
  end;

  function go(a:longint):big;
  var
    t:big;
  begin
    if a=1 then begin
      with t do begin
        len:=1;
        fillchar(data,sizeof(data),0);
        data[1]:=1;
      end;
      exit(t);
    end;
    go:=jia1(cheng2(go(a-1)));
  end;

  procedure output(a:big);
  var
    i:longint;
  begin
    with a do begin
	  for i:=len downto 1 do write(data[i]);
	end;
  end;
begin
  readln(n);
  output(cheng2(go(n)));
end.
