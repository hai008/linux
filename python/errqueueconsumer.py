#!/usr/bin/env python
# -*- coding:utf-8 -*-

import pika
import json
import sys


reload(sys)
sys.setdefaultencoding('utf-8')



username = 'l'
pwd = 'l'
user_pwd = pika.PlainCredentials(username, pwd)
s_conn = pika.BlockingConnection(pika.ConnectionParameters(host='192.168.127.128', port=80, credentials=user_pwd))
chan = s_conn.channel()

def callback(ch,method,properties,body):
	jBody = json.loads(body)
	print("[test] recv %s" % body)


chan.basic_consume(callback, queue='test', no_ack=True)
print('[consumer] waiting for msg .')
chan.start_consuming()
