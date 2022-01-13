import subprocess
import os 
import shutil
import datetime

outdir="output/"
outBackupDir="output_backup/"
logFileName=outdir+"log.txt"
impala="../../impala/build/bin/impala"

# create thorin code
# output conclusion

if os.path.exists(outdir):
    shutil.rmtree(outdir)

try:
    os.mkdir(outdir)
except FileExistsError:
    pass

logfile=open(logFileName,"a")

def log(s):
    print(s)
    logfile.write(s+"\n")

for root, dirs, files in sorted(os.walk(".")):
    if "output" in root:
        continue
    # print(root,dirs,files)
    # log(root)
    try:
        os.mkdir(outdir+root)
    except FileExistsError:
        pass

    for f in files:
        if not f.endswith(".impala") or "disabled" in f:
            continue
        filestump=f.split(".")[0]
        filename=root+"/"+f
        # out=subprocess.check_output([impala, "--help"])
        # p=subprocess.Popen([impala, "--help"],stdout=subprocess.PIPE,stderr=subprocess.PIPE)
        # out,err=p.communicate()
        # log(p.output)
        # print(str(out))
        shutil.copyfile(filename,outdir+filename)
        for suffix,args in [("thorin",["-emit-thorin"]),("optmized",["-Othorin","-emit-thorin"])]:
            # p=subprocess.run([impala]+args+[filename], capture_output=True)

            cmd=[impala]+args+[filename]
            p=subprocess.Popen(cmd,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
            out=""
            for l in p.stdout:
                out+=l.decode("utf-8")
            outc,errc=p.communicate()
            if p.returncode == 0:
                log("👍"+filename+" "+suffix+": okay")
            else:
                log("💩"+filename+" "+suffix+": error")
                log("    "+" ".join(cmd))
                # print(out)
                # print(outc)
                # print(errc)
                # exit(0)
            # returncode=0
            # try:
            #     out=subprocess.check_output([impala]+args+[filename])
            # except subprocess.CalledProcessError as exc: 
            #     returncode=exc.returncode
            #     out=exc.output
            #     print(dir(exc))
            #     print(exc.output)
            #     print(exc.stdout)
            #     print(exc.stderr)
            #     # exc.output
            #     # exc.returncode
            # out=out.decode("utf-8")
            # # print(out)
            # # exit(0)
            # # p=subprocess.Popen([impala]+args+[filename],stdout=subprocess.PIPE,stderr=subprocess.PIPE)
            # # out,err=p.communicate()
            # # p=subprocess.run([impala]+args+[filename], capture_output=True)
            # # out=(p.stdout.decode("utf-8"))
            # if returncode == 0:
            #     log("👍"+filename+" "+suffix+": okay")
            # else:
            #     log("💩"+filename+" "+suffix+": error")
            #     print(out)
            #     # print(p.stdout)
            #     # print(p.stderr)
            #     # print(dir(p))
            #     # print([impala]+args+[filename])
            #     exit(0)
            #     err=(p.stderr.decode("utf-8"))
            #     with open(outdir+root+"/"+filestump+"_"+suffix+"_err.txt","w") as f:
            #         f.write(err)
            with open(outdir+root+"/"+filestump+"_"+suffix+"_out.txt","w") as f:
                f.write(out)

# subprocess.run(["ls", "-l", "/dev/null"], capture_output=True)
try:
    os.mkdir(outBackupDir)
except FileExistsError:
    pass
now=datetime.datetime.now()
shutil.make_archive(outBackupDir+now.strftime("%Y-%m-%d_%H-%M-%S"),"zip",outdir)