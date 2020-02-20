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


class AnalyzerProtocolCountersEthernet(object):
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
        'ip': 'int',
        'timesync': 'int',
        'arp': 'int',
        'lldp': 'int',
        'nsh': 'int',
        'vlan': 'int',
        'qinq': 'int',
        'pppoe': 'int',
        'fcoe': 'int',
        'mpls': 'int'
    }

    attribute_map = {
        'ip': 'ip',
        'timesync': 'timesync',
        'arp': 'arp',
        'lldp': 'lldp',
        'nsh': 'nsh',
        'vlan': 'vlan',
        'qinq': 'qinq',
        'pppoe': 'pppoe',
        'fcoe': 'fcoe',
        'mpls': 'mpls'
    }

    def __init__(self, ip=None, timesync=None, arp=None, lldp=None, nsh=None, vlan=None, qinq=None, pppoe=None, fcoe=None, mpls=None):  # noqa: E501
        """AnalyzerProtocolCountersEthernet - a model defined in Swagger"""  # noqa: E501

        self._ip = None
        self._timesync = None
        self._arp = None
        self._lldp = None
        self._nsh = None
        self._vlan = None
        self._qinq = None
        self._pppoe = None
        self._fcoe = None
        self._mpls = None
        self.discriminator = None

        self.ip = ip
        self.timesync = timesync
        self.arp = arp
        self.lldp = lldp
        self.nsh = nsh
        self.vlan = vlan
        self.qinq = qinq
        self.pppoe = pppoe
        self.fcoe = fcoe
        self.mpls = mpls

    @property
    def ip(self):
        """Gets the ip of this AnalyzerProtocolCountersEthernet.  # noqa: E501

        Number of IPv4/IPv6 frames  # noqa: E501

        :return: The ip of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :rtype: int
        """
        return self._ip

    @ip.setter
    def ip(self, ip):
        """Sets the ip of this AnalyzerProtocolCountersEthernet.

        Number of IPv4/IPv6 frames  # noqa: E501

        :param ip: The ip of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :type: int
        """
        self._ip = ip

    @property
    def timesync(self):
        """Gets the timesync of this AnalyzerProtocolCountersEthernet.  # noqa: E501

        Number of Precision Time Protocol frames  # noqa: E501

        :return: The timesync of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :rtype: int
        """
        return self._timesync

    @timesync.setter
    def timesync(self, timesync):
        """Sets the timesync of this AnalyzerProtocolCountersEthernet.

        Number of Precision Time Protocol frames  # noqa: E501

        :param timesync: The timesync of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :type: int
        """
        self._timesync = timesync

    @property
    def arp(self):
        """Gets the arp of this AnalyzerProtocolCountersEthernet.  # noqa: E501

        Number of Address Resolution Protocol frames  # noqa: E501

        :return: The arp of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :rtype: int
        """
        return self._arp

    @arp.setter
    def arp(self, arp):
        """Sets the arp of this AnalyzerProtocolCountersEthernet.

        Number of Address Resolution Protocol frames  # noqa: E501

        :param arp: The arp of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :type: int
        """
        self._arp = arp

    @property
    def lldp(self):
        """Gets the lldp of this AnalyzerProtocolCountersEthernet.  # noqa: E501

        Number of Link Layer Discover Protocol frames  # noqa: E501

        :return: The lldp of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :rtype: int
        """
        return self._lldp

    @lldp.setter
    def lldp(self, lldp):
        """Sets the lldp of this AnalyzerProtocolCountersEthernet.

        Number of Link Layer Discover Protocol frames  # noqa: E501

        :param lldp: The lldp of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :type: int
        """
        self._lldp = lldp

    @property
    def nsh(self):
        """Gets the nsh of this AnalyzerProtocolCountersEthernet.  # noqa: E501

        Number of Network Service Header frames  # noqa: E501

        :return: The nsh of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :rtype: int
        """
        return self._nsh

    @nsh.setter
    def nsh(self, nsh):
        """Sets the nsh of this AnalyzerProtocolCountersEthernet.

        Number of Network Service Header frames  # noqa: E501

        :param nsh: The nsh of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :type: int
        """
        self._nsh = nsh

    @property
    def vlan(self):
        """Gets the vlan of this AnalyzerProtocolCountersEthernet.  # noqa: E501

        Number of Virtual LAN frames  # noqa: E501

        :return: The vlan of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :rtype: int
        """
        return self._vlan

    @vlan.setter
    def vlan(self, vlan):
        """Sets the vlan of this AnalyzerProtocolCountersEthernet.

        Number of Virtual LAN frames  # noqa: E501

        :param vlan: The vlan of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :type: int
        """
        self._vlan = vlan

    @property
    def qinq(self):
        """Gets the qinq of this AnalyzerProtocolCountersEthernet.  # noqa: E501

        Number of Queue-in-Queue frames  # noqa: E501

        :return: The qinq of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :rtype: int
        """
        return self._qinq

    @qinq.setter
    def qinq(self, qinq):
        """Sets the qinq of this AnalyzerProtocolCountersEthernet.

        Number of Queue-in-Queue frames  # noqa: E501

        :param qinq: The qinq of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :type: int
        """
        self._qinq = qinq

    @property
    def pppoe(self):
        """Gets the pppoe of this AnalyzerProtocolCountersEthernet.  # noqa: E501

        Number of PPP over Ethernet frames  # noqa: E501

        :return: The pppoe of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :rtype: int
        """
        return self._pppoe

    @pppoe.setter
    def pppoe(self, pppoe):
        """Sets the pppoe of this AnalyzerProtocolCountersEthernet.

        Number of PPP over Ethernet frames  # noqa: E501

        :param pppoe: The pppoe of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :type: int
        """
        self._pppoe = pppoe

    @property
    def fcoe(self):
        """Gets the fcoe of this AnalyzerProtocolCountersEthernet.  # noqa: E501

        Number of Fiber Channel over Ethernet frames  # noqa: E501

        :return: The fcoe of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :rtype: int
        """
        return self._fcoe

    @fcoe.setter
    def fcoe(self, fcoe):
        """Sets the fcoe of this AnalyzerProtocolCountersEthernet.

        Number of Fiber Channel over Ethernet frames  # noqa: E501

        :param fcoe: The fcoe of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :type: int
        """
        self._fcoe = fcoe

    @property
    def mpls(self):
        """Gets the mpls of this AnalyzerProtocolCountersEthernet.  # noqa: E501

        Number of Multi Protocol Label Switched frames  # noqa: E501

        :return: The mpls of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :rtype: int
        """
        return self._mpls

    @mpls.setter
    def mpls(self, mpls):
        """Sets the mpls of this AnalyzerProtocolCountersEthernet.

        Number of Multi Protocol Label Switched frames  # noqa: E501

        :param mpls: The mpls of this AnalyzerProtocolCountersEthernet.  # noqa: E501
        :type: int
        """
        self._mpls = mpls

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
        if not isinstance(other, AnalyzerProtocolCountersEthernet):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
