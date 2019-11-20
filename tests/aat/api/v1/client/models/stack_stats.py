# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six

from client.models.stack_element_stats import StackElementStats  # noqa: F401,E501
from client.models.stack_memory_stats import StackMemoryStats  # noqa: F401,E501
from client.models.stack_protocol_stats import StackProtocolStats  # noqa: F401,E501


class StackStats(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'arp': 'StackProtocolStats',
        'ipv4': 'StackProtocolStats',
        'ipv4_frag': 'StackProtocolStats',
        'icmpv4': 'StackProtocolStats',
        'igmp': 'StackProtocolStats',
        'nd': 'StackProtocolStats',
        'ipv6': 'StackProtocolStats',
        'ipv6_frag': 'StackProtocolStats',
        'icmpv6': 'StackProtocolStats',
        'mld': 'StackProtocolStats',
        'udp': 'StackProtocolStats',
        'tcp': 'StackProtocolStats',
        'heap': 'StackMemoryStats',
        'pools': 'list[StackMemoryStats]',
        'sems': 'StackElementStats',
        'mutexes': 'StackElementStats',
        'mboxes': 'StackElementStats'
    }

    attribute_map = {
        'arp': 'arp',
        'ipv4': 'ipv4',
        'ipv4_frag': 'ipv4_frag',
        'icmpv4': 'icmpv4',
        'igmp': 'igmp',
        'nd': 'nd',
        'ipv6': 'ipv6',
        'ipv6_frag': 'ipv6_frag',
        'icmpv6': 'icmpv6',
        'mld': 'mld',
        'udp': 'udp',
        'tcp': 'tcp',
        'heap': 'heap',
        'pools': 'pools',
        'sems': 'sems',
        'mutexes': 'mutexes',
        'mboxes': 'mboxes'
    }

    def __init__(self, arp=None, ipv4=None, ipv4_frag=None, icmpv4=None, igmp=None, nd=None, ipv6=None, ipv6_frag=None, icmpv6=None, mld=None, udp=None, tcp=None, heap=None, pools=None, sems=None, mutexes=None, mboxes=None):  # noqa: E501
        """StackStats - a model defined in Swagger"""  # noqa: E501

        self._arp = None
        self._ipv4 = None
        self._ipv4_frag = None
        self._icmpv4 = None
        self._igmp = None
        self._nd = None
        self._ipv6 = None
        self._ipv6_frag = None
        self._icmpv6 = None
        self._mld = None
        self._udp = None
        self._tcp = None
        self._heap = None
        self._pools = None
        self._sems = None
        self._mutexes = None
        self._mboxes = None
        self.discriminator = None

        self.arp = arp
        self.ipv4 = ipv4
        self.ipv4_frag = ipv4_frag
        self.icmpv4 = icmpv4
        self.igmp = igmp
        self.nd = nd
        self.ipv6 = ipv6
        self.ipv6_frag = ipv6_frag
        self.icmpv6 = icmpv6
        self.mld = mld
        self.udp = udp
        self.tcp = tcp
        self.heap = heap
        self.pools = pools
        self.sems = sems
        self.mutexes = mutexes
        self.mboxes = mboxes

    @property
    def arp(self):
        """Gets the arp of this StackStats.  # noqa: E501


        :return: The arp of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._arp

    @arp.setter
    def arp(self, arp):
        """Sets the arp of this StackStats.


        :param arp: The arp of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._arp = arp

    @property
    def ipv4(self):
        """Gets the ipv4 of this StackStats.  # noqa: E501


        :return: The ipv4 of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._ipv4

    @ipv4.setter
    def ipv4(self, ipv4):
        """Sets the ipv4 of this StackStats.


        :param ipv4: The ipv4 of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._ipv4 = ipv4

    @property
    def ipv4_frag(self):
        """Gets the ipv4_frag of this StackStats.  # noqa: E501


        :return: The ipv4_frag of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._ipv4_frag

    @ipv4_frag.setter
    def ipv4_frag(self, ipv4_frag):
        """Sets the ipv4_frag of this StackStats.


        :param ipv4_frag: The ipv4_frag of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._ipv4_frag = ipv4_frag

    @property
    def icmpv4(self):
        """Gets the icmpv4 of this StackStats.  # noqa: E501


        :return: The icmpv4 of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._icmpv4

    @icmpv4.setter
    def icmpv4(self, icmpv4):
        """Sets the icmpv4 of this StackStats.


        :param icmpv4: The icmpv4 of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._icmpv4 = icmpv4

    @property
    def igmp(self):
        """Gets the igmp of this StackStats.  # noqa: E501


        :return: The igmp of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._igmp

    @igmp.setter
    def igmp(self, igmp):
        """Sets the igmp of this StackStats.


        :param igmp: The igmp of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._igmp = igmp

    @property
    def nd(self):
        """Gets the nd of this StackStats.  # noqa: E501


        :return: The nd of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._nd

    @nd.setter
    def nd(self, nd):
        """Sets the nd of this StackStats.


        :param nd: The nd of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._nd = nd

    @property
    def ipv6(self):
        """Gets the ipv6 of this StackStats.  # noqa: E501


        :return: The ipv6 of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._ipv6

    @ipv6.setter
    def ipv6(self, ipv6):
        """Sets the ipv6 of this StackStats.


        :param ipv6: The ipv6 of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._ipv6 = ipv6

    @property
    def ipv6_frag(self):
        """Gets the ipv6_frag of this StackStats.  # noqa: E501


        :return: The ipv6_frag of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._ipv6_frag

    @ipv6_frag.setter
    def ipv6_frag(self, ipv6_frag):
        """Sets the ipv6_frag of this StackStats.


        :param ipv6_frag: The ipv6_frag of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._ipv6_frag = ipv6_frag

    @property
    def icmpv6(self):
        """Gets the icmpv6 of this StackStats.  # noqa: E501


        :return: The icmpv6 of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._icmpv6

    @icmpv6.setter
    def icmpv6(self, icmpv6):
        """Sets the icmpv6 of this StackStats.


        :param icmpv6: The icmpv6 of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._icmpv6 = icmpv6

    @property
    def mld(self):
        """Gets the mld of this StackStats.  # noqa: E501


        :return: The mld of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._mld

    @mld.setter
    def mld(self, mld):
        """Sets the mld of this StackStats.


        :param mld: The mld of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._mld = mld

    @property
    def udp(self):
        """Gets the udp of this StackStats.  # noqa: E501


        :return: The udp of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._udp

    @udp.setter
    def udp(self, udp):
        """Sets the udp of this StackStats.


        :param udp: The udp of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._udp = udp

    @property
    def tcp(self):
        """Gets the tcp of this StackStats.  # noqa: E501


        :return: The tcp of this StackStats.  # noqa: E501
        :rtype: StackProtocolStats
        """
        return self._tcp

    @tcp.setter
    def tcp(self, tcp):
        """Sets the tcp of this StackStats.


        :param tcp: The tcp of this StackStats.  # noqa: E501
        :type: StackProtocolStats
        """
        self._tcp = tcp

    @property
    def heap(self):
        """Gets the heap of this StackStats.  # noqa: E501


        :return: The heap of this StackStats.  # noqa: E501
        :rtype: StackMemoryStats
        """
        return self._heap

    @heap.setter
    def heap(self, heap):
        """Sets the heap of this StackStats.


        :param heap: The heap of this StackStats.  # noqa: E501
        :type: StackMemoryStats
        """
        self._heap = heap

    @property
    def pools(self):
        """Gets the pools of this StackStats.  # noqa: E501


        :return: The pools of this StackStats.  # noqa: E501
        :rtype: list[StackMemoryStats]
        """
        return self._pools

    @pools.setter
    def pools(self, pools):
        """Sets the pools of this StackStats.


        :param pools: The pools of this StackStats.  # noqa: E501
        :type: list[StackMemoryStats]
        """
        self._pools = pools

    @property
    def sems(self):
        """Gets the sems of this StackStats.  # noqa: E501


        :return: The sems of this StackStats.  # noqa: E501
        :rtype: StackElementStats
        """
        return self._sems

    @sems.setter
    def sems(self, sems):
        """Sets the sems of this StackStats.


        :param sems: The sems of this StackStats.  # noqa: E501
        :type: StackElementStats
        """
        self._sems = sems

    @property
    def mutexes(self):
        """Gets the mutexes of this StackStats.  # noqa: E501


        :return: The mutexes of this StackStats.  # noqa: E501
        :rtype: StackElementStats
        """
        return self._mutexes

    @mutexes.setter
    def mutexes(self, mutexes):
        """Sets the mutexes of this StackStats.


        :param mutexes: The mutexes of this StackStats.  # noqa: E501
        :type: StackElementStats
        """
        self._mutexes = mutexes

    @property
    def mboxes(self):
        """Gets the mboxes of this StackStats.  # noqa: E501


        :return: The mboxes of this StackStats.  # noqa: E501
        :rtype: StackElementStats
        """
        return self._mboxes

    @mboxes.setter
    def mboxes(self, mboxes):
        """Sets the mboxes of this StackStats.


        :param mboxes: The mboxes of this StackStats.  # noqa: E501
        :type: StackElementStats
        """
        self._mboxes = mboxes

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, StackStats):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
