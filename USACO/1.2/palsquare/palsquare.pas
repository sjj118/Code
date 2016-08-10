{
ID: sjj22451
LANG: PASCAL
PROB: palsquare
}
const
  h:array[0..19]of char=('0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J');
type
  big=record
    len:longint;
	data:array[1..50]of longint;
  end;
var
  b,i,j:longint;
  a,t:big;

  function sqr(a:big):big;
  var
    i,j:longint;
  begin
    sqr.len:=a.len*2-1;
	fillchar(sqr.data,sizeof(sqr.data),0);
	for i:=1 to a.len do begin
	  for j:=1 to a.len do begin
	    sqr.data[i+j-1]:=sqr.data[i+j-1]+a.data[i]*a.data[j];
	  end;
	end;
	for i:=1 to i+j-1 do begin
	  sqr.data[i+1]:=sqr.data[i+1]+sqr.data[i] div b;
	  sqr.data[i]:=sqr.data[i] mod b;
	end;
	if sqr.data[sqr.len+1]>0 then inc(sqr.len);
  end;

  function check(a:big):boolean;
  var
    i:longint;
  begin
    with a do begin
	  for i:=1 to len div 2 do if data[i]<>data[len-i+1] then exit(false);
	end;
	exit(true);
  end;

  procedure print(a:big);
  var
    i:longint;
  begin
    for i:=a.len downto 1 do write(h[a.data[i]]);
  end;
begin
  assign(input,'palsquare.in');reset(input);assign(output,'palsquare.out');rewrite(output);
  readln(b);
  with a do begin
    len:=1;
	fillchar(data,sizeof(data),0);
	for i:=1 to 300 do begin
	  inc(data[1]);
	  j:=1;
	  while data[j]>=b do begin
	    data[j+1]:=data[j+1]+data[j] div b;
		data[j]:=data[j] mod b;
                inc(j);
	  end;
	  if data[len+1]>0 then inc(len);
	  t:=sqr(a);
	  if check(t) then begin
	    print(a);
		write(' ');
		print(t);
		writeln;
	  end;
	end;
  end;
  close(input);close(output);
end.
