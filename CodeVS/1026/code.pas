const
	dir:array[1..2,1..4]of longint=((-1,1,0,0),(0,0,-1,1));
var
	map:array[0..51,0..51]of char;
	path:array[1..1000]of byte;
	n,r,c,i,j,x,y:longint;
	flag:array[0..51,0..51,1..1000]of boolean;
	s:string;
	
	procedure go(x,y,k:longint);
	begin
		flag[x,y,k]:=true;
		if map[x,y]='X' then exit;
		if k=n then begin
			map[x,y]:='*';
			if not flag[x+dir[1,path[k]],y+dir[2,path[k]],k] then go(x+dir[1,path[k]],y+dir[2,path[k]],k);
		end else if k=0 then begin
			if not flag[x+dir[1,path[k+1]],y+dir[2,path[k+1]],k+1] then go(x+dir[1,path[k+1]],y+dir[2,path[k+1]],k+1);
		end else begin
			if not flag[x+dir[1,path[k]],y+dir[2,path[k]],k] then go(x+dir[1,path[k]],y+dir[2,path[k]],k);
			if not flag[x+dir[1,path[k+1]],y+dir[2,path[k+1]],k+1] then go(x+dir[1,path[k+1]],y+dir[2,path[k+1]],k+1);
		end;
	end;
begin
	readln(r,c);
	fillchar(map,sizeof(map),'X');
	for i:=1 to r do begin
		for j:=1 to c do begin
			read(map[i,j]);
			if map[i,j]='*' then begin x:=i; y:=j; end;
		end;
		readln;
	end;
	readln(n);
	for i:=1 to n do begin
		readln(s);
		if s='NORTH' then path[i]:=1
		else if s='SOUTH' then path[i]:=2
		else if s='WEST' then path[i]:=3
		else if s='EAST' then path[i]:=4;
	end;
        map[x,y]:='.';
        go(x,y,0);
	for i:=1 to r do begin
		for j:=1 to c do write(map[i,j]);
		writeln;
	end;
end.
