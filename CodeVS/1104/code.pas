var
	n,i,max,sum,p1,p2:longint;
	c:char;
	nam:array[1..100]of string;
	qi,ban,lun,m:array[1..100]of longint;
	gan,xi:array[1..100]of char;
begin
	readln(n);
	for i:=1 to n do begin
		read(c);
		while c<>' ' do begin
			nam[i]:=nam[i]+c;
			read(c);
		end;
		read(c);
		while c<>' ' do begin
			qi[i]:=qi[i]*10+ord(c)-ord('0');
			read(c);
		end;
		read(c);
		while c<>' ' do begin
			ban[i]:=ban[i]*10+ord(c)-ord('0');
			read(c);
		end;
		read(gan[i]);
		read(c);
		read(xi[i]);
		read(c);
		read(c);
		while (c<>' ') do begin
			lun[i]:=lun[i]*10+ord(c)-ord('0');
                        if eoln then break;
			read(c);
		end;
	end;
	for i:=1 to n do begin
		if (qi[i]>80)and(lun[i]>=1) then m[i]:=m[i]+8000;
		if (qi[i]>85)and(ban[i]>80) then m[i]:=m[i]+4000;
		if (qi[i]>90) then m[i]:=m[i]+2000;
		if (qi[i]>85)and(xi[i]='Y') then m[i]:=m[i]+1000;
		if (ban[i]>80)and(gan[i]='Y') then m[i]:=m[i]+850;
	end;
	max:=1;
	for i:=1 to n do sum:=sum+m[i];
	for i:=2 to n do if m[i]>m[max] then max:=i;
	writeln(nam[max]);
	writeln(m[max]);
	writeln(sum);
end.
