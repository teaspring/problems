# available nntp server: group
# mcadams.posc.mu.edu: alt.assassination.jfk
# news.php.net: php.dev

from nntplib import NNTP
from time import strftime, time, localtime
day = 24 * 60 * 60  # seconds of one day

yesterday = localtime(time() - day)
date = strftime('%y%m%d', yesterday)
hour = strftime('%H%M%S', yesterday)

servername = 'mcadams.posc.mu.edu'
group = 'alt.assassination.jfk'
server = NNTP(servername)

ids = server.newnews(group, date, hour)[1]
for id in ids:
    head = server.head(id)[3]  # 4th element
    for line in head:
        if line.lower().startswith('subject:'):
            subject = line[9:]
            break

    body = server.body(id)[3]
    print subject
    print '-'*len(subject)
    print '\n'.join(body)
server.quit()


