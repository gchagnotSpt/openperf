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

from client.models.analyzer_protocol_counters_ethernet import AnalyzerProtocolCountersEthernet  # noqa: F401,E501
from client.models.analyzer_protocol_counters_inner_ethernet import AnalyzerProtocolCountersInnerEthernet  # noqa: F401,E501
from client.models.analyzer_protocol_counters_inner_ip import AnalyzerProtocolCountersInnerIp  # noqa: F401,E501
from client.models.analyzer_protocol_counters_inner_protocol import AnalyzerProtocolCountersInnerProtocol  # noqa: F401,E501
from client.models.analyzer_protocol_counters_ip import AnalyzerProtocolCountersIp  # noqa: F401,E501
from client.models.analyzer_protocol_counters_protocol import AnalyzerProtocolCountersProtocol  # noqa: F401,E501
from client.models.analyzer_protocol_counters_tunnel import AnalyzerProtocolCountersTunnel  # noqa: F401,E501


class AnalyzerProtocolCounters(object):
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
        'ethernet': 'AnalyzerProtocolCountersEthernet',
        'ip': 'AnalyzerProtocolCountersIp',
        'protocol': 'AnalyzerProtocolCountersProtocol',
        'tunnel': 'AnalyzerProtocolCountersTunnel',
        'inner_ethernet': 'AnalyzerProtocolCountersInnerEthernet',
        'inner_ip': 'AnalyzerProtocolCountersInnerIp',
        'inner_protocol': 'AnalyzerProtocolCountersInnerProtocol'
    }

    attribute_map = {
        'ethernet': 'ethernet',
        'ip': 'ip',
        'protocol': 'protocol',
        'tunnel': 'tunnel',
        'inner_ethernet': 'inner_ethernet',
        'inner_ip': 'inner_ip',
        'inner_protocol': 'inner_protocol'
    }

    def __init__(self, ethernet=None, ip=None, protocol=None, tunnel=None, inner_ethernet=None, inner_ip=None, inner_protocol=None):  # noqa: E501
        """AnalyzerProtocolCounters - a model defined in Swagger"""  # noqa: E501

        self._ethernet = None
        self._ip = None
        self._protocol = None
        self._tunnel = None
        self._inner_ethernet = None
        self._inner_ip = None
        self._inner_protocol = None
        self.discriminator = None

        if ethernet is not None:
            self.ethernet = ethernet
        if ip is not None:
            self.ip = ip
        if protocol is not None:
            self.protocol = protocol
        if tunnel is not None:
            self.tunnel = tunnel
        if inner_ethernet is not None:
            self.inner_ethernet = inner_ethernet
        if inner_ip is not None:
            self.inner_ip = inner_ip
        if inner_protocol is not None:
            self.inner_protocol = inner_protocol

    @property
    def ethernet(self):
        """Gets the ethernet of this AnalyzerProtocolCounters.  # noqa: E501


        :return: The ethernet of this AnalyzerProtocolCounters.  # noqa: E501
        :rtype: AnalyzerProtocolCountersEthernet
        """
        return self._ethernet

    @ethernet.setter
    def ethernet(self, ethernet):
        """Sets the ethernet of this AnalyzerProtocolCounters.


        :param ethernet: The ethernet of this AnalyzerProtocolCounters.  # noqa: E501
        :type: AnalyzerProtocolCountersEthernet
        """
        self._ethernet = ethernet

    @property
    def ip(self):
        """Gets the ip of this AnalyzerProtocolCounters.  # noqa: E501


        :return: The ip of this AnalyzerProtocolCounters.  # noqa: E501
        :rtype: AnalyzerProtocolCountersIp
        """
        return self._ip

    @ip.setter
    def ip(self, ip):
        """Sets the ip of this AnalyzerProtocolCounters.


        :param ip: The ip of this AnalyzerProtocolCounters.  # noqa: E501
        :type: AnalyzerProtocolCountersIp
        """
        self._ip = ip

    @property
    def protocol(self):
        """Gets the protocol of this AnalyzerProtocolCounters.  # noqa: E501


        :return: The protocol of this AnalyzerProtocolCounters.  # noqa: E501
        :rtype: AnalyzerProtocolCountersProtocol
        """
        return self._protocol

    @protocol.setter
    def protocol(self, protocol):
        """Sets the protocol of this AnalyzerProtocolCounters.


        :param protocol: The protocol of this AnalyzerProtocolCounters.  # noqa: E501
        :type: AnalyzerProtocolCountersProtocol
        """
        self._protocol = protocol

    @property
    def tunnel(self):
        """Gets the tunnel of this AnalyzerProtocolCounters.  # noqa: E501


        :return: The tunnel of this AnalyzerProtocolCounters.  # noqa: E501
        :rtype: AnalyzerProtocolCountersTunnel
        """
        return self._tunnel

    @tunnel.setter
    def tunnel(self, tunnel):
        """Sets the tunnel of this AnalyzerProtocolCounters.


        :param tunnel: The tunnel of this AnalyzerProtocolCounters.  # noqa: E501
        :type: AnalyzerProtocolCountersTunnel
        """
        self._tunnel = tunnel

    @property
    def inner_ethernet(self):
        """Gets the inner_ethernet of this AnalyzerProtocolCounters.  # noqa: E501


        :return: The inner_ethernet of this AnalyzerProtocolCounters.  # noqa: E501
        :rtype: AnalyzerProtocolCountersInnerEthernet
        """
        return self._inner_ethernet

    @inner_ethernet.setter
    def inner_ethernet(self, inner_ethernet):
        """Sets the inner_ethernet of this AnalyzerProtocolCounters.


        :param inner_ethernet: The inner_ethernet of this AnalyzerProtocolCounters.  # noqa: E501
        :type: AnalyzerProtocolCountersInnerEthernet
        """
        self._inner_ethernet = inner_ethernet

    @property
    def inner_ip(self):
        """Gets the inner_ip of this AnalyzerProtocolCounters.  # noqa: E501


        :return: The inner_ip of this AnalyzerProtocolCounters.  # noqa: E501
        :rtype: AnalyzerProtocolCountersInnerIp
        """
        return self._inner_ip

    @inner_ip.setter
    def inner_ip(self, inner_ip):
        """Sets the inner_ip of this AnalyzerProtocolCounters.


        :param inner_ip: The inner_ip of this AnalyzerProtocolCounters.  # noqa: E501
        :type: AnalyzerProtocolCountersInnerIp
        """
        self._inner_ip = inner_ip

    @property
    def inner_protocol(self):
        """Gets the inner_protocol of this AnalyzerProtocolCounters.  # noqa: E501


        :return: The inner_protocol of this AnalyzerProtocolCounters.  # noqa: E501
        :rtype: AnalyzerProtocolCountersInnerProtocol
        """
        return self._inner_protocol

    @inner_protocol.setter
    def inner_protocol(self, inner_protocol):
        """Sets the inner_protocol of this AnalyzerProtocolCounters.


        :param inner_protocol: The inner_protocol of this AnalyzerProtocolCounters.  # noqa: E501
        :type: AnalyzerProtocolCountersInnerProtocol
        """
        self._inner_protocol = inner_protocol

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
        if not isinstance(other, AnalyzerProtocolCounters):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
